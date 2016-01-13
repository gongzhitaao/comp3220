var gulp = require('gulp');
var path = require('path');
var concat = require('gulp-concat');
var cssnano = require('gulp-cssnano');
var htmlmin = require('gulp-htmlmin');
var autoprefixer = require('gulp-autoprefixer');
var browsersync = require('browser-sync');
var flatten = require('gulp-flatten');
var watch = require('gulp-watch');
var rsync = require('gulp-rsync');

var dist = '../gh-pages';

gulp.task('default', ['browser-sync', 'homepage', 'copy']);

// -------------------------------------------------------------------
// browser-sync
// -------------------------------------------------------------------
gulp.task('browser-sync', function() {
  browsersync({
    server: {
      baseDir: dist
    },
    port: 4000,
    files: [
      path.join(dist, 'css/*.css'),
      path.join(dist, 'index.html')
    ]
  });
});

// -------------------------------------------------------------------
// homepage
// -------------------------------------------------------------------
gulp.task('homepage', ['optimize-css', 'optimize-html']);

gulp.task('optimize-html', function() {
  return gulp.src('homepage/index.html')
    .pipe(watch('homepage/index.html', {verbose: true}))
    .pipe(htmlmin({
      removeComments: true,
      collapseWhitespace: true,
      removeEmptyAttributes: true,
      minifyJS: true,
      minifyCSS: true
    }))
    .pipe(gulp.dest(dist));
});

gulp.task('optimize-css', function() {
  return gulp.src('homepage/css/*.css')
    .pipe(watch('homepage/css/*.css', {verbose: true}))
    .pipe(cssnano())
    .pipe(autoprefixer({ browsers: ['last 2 version']}))
    .pipe(concat('css/ppl.css'))
    .pipe(gulp.dest(dist));
});

// -------------------------------------------------------------------
// copy
// -------------------------------------------------------------------
gulp.task('copy', ['copy-slide', 'copy-assignment', 'copy-exam']);

gulp.task('copy-slide', function(){
  var p = path.join('build', 'slide', '**', '*.@(pdf|zip)');
  return gulp.src(p)
    .pipe(watch(p, {verbose: true}))
    .pipe(flatten())
    .pipe(gulp.dest(path.join(dist, 'slide')));
});

gulp.task('copy-assignment', function(){
  var p = path.join('build', 'assignment', '**', '*.@(pdf|zip)');
  return gulp.src(p)
    .pipe(watch(p, {verbose: true}))
    .pipe(flatten())
    .pipe(gulp.dest(path.join(dist, 'assignment')));
});

gulp.task('copy-exam', function(){
  var p = path.join('build', 'exam', '**', '*.@(pdf|zip)');
  return gulp.src(p)
    .pipe(watch(p, {verbose: true}))
    .pipe(flatten())
    .pipe(gulp.dest(path.join(dist, 'exam')));
});

gulp.task('deploy', function() {
  gulp.src(dist)
    .pipe(rsync({
      root: dist,
      hostname: 'mallard',
      destination: '~/public_html/comp3220/spring2016',
      progress: true,
      compress: true,
      recursive: true,
      update: true,
      exclude: ['.git', '.gitignore', '.jekyll-metadata']
    }));
});
