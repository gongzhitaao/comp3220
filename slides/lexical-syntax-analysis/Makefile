TEXI2PDF = texi2pdf
IMGDIR = img
NAME = lexical-syntax-structure lexical-syntax-structure-2 lex-process

all : $(NAME) clean

% : $(IMGDIR)/%.tex
	$(TEXI2PDF) $< && mv $@.svg $(IMGDIR) && trash $@.pdf

clean :
	rm -rf *.aux *.log

.PHONY : all clean
