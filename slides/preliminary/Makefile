TEXI2PDF = texi2pdf
IMGDIR = img
NAME = von-neumann-arch layered-view whole-compile-process	\
	whole-compile-process-cpp whole-process-simplified	\
	compile-process interprete-process byte-compile-process

all : $(NAME) clean

% : $(IMGDIR)/%.tex
	$(TEXI2PDF) $< && mv $@.svg $(IMGDIR) && trash $@.pdf

clean :
	rm -rf *.aux *.log

.PHONY : all clean
