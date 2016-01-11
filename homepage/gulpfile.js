var gulp = require('gulp');
var concat = require('gulp-concat');
var cssnano = require('gulp-cssnano');
var autoprefixer = require('gulp-autoprefixer');
var browsersync = require('browser-sync');

var src = 'css';
var dist = '../../gh-pages';

gulp.task('default', ['browser-sync'], function() {
    gulp.watch(src + '/*.css', ['optimize-css']);
});

gulp.task('browser-sync', function() {
  browsersync({
    server: {
      baseDir: dist
    },
    port: 4000,
    files: [
      dist + '/css/*.css',
      dist + '/*.html'
    ]
  });
});

gulp.task('optimize-css', function() {
  return gulp.src(src + '/*.css')
    .pipe(cssnano())
    .pipe(autoprefixer({ browsers: ['last 2 version']}))
    .pipe(concat('css/ppl.css'))
    .pipe(gulp.dest(dist));
});
