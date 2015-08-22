TEXI2PDF = texi2pdf
IMGDIR = img
NAME = recognizer generator chomsky-hierarchy parse-tree-ex1	\
	ambiguous-grammar-a ambiguous-grammar-b			\
	inherently-ambiguous-ex cfg-def

all : $(NAME) clean

% : $(IMGDIR)/%.tex
	$(TEXI2PDF) $< && mv $@.svg $(IMGDIR) && trash $@.pdf

clean :
	rm -rf *.aux *.log

.PHONY : all clean
