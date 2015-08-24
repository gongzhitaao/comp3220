TEXI2PDF = texi2pdf
IMGDIR = img
NAME = recognizer generator chomsky-hierarchy parse-tree-ex1	\
	ambiguous-grammar-a ambiguous-grammar-b			\
	inherently-ambiguous-ex cfg-def parse-tree-ag-ex1	\
	parse-tree-ag-ex2 parse-tree-ds-ex1 inference-rule	\
	assignment-axiom proof-correctness consequence-rule	\
	sequence-inference loop-inference

all : $(NAME) clean

% : $(IMGDIR)/%.tex
	$(TEXI2PDF) $< && mv $@.svg $(IMGDIR) && trash $@.pdf

clean :
	rm -rf *.aux *.log

.PHONY : all clean
