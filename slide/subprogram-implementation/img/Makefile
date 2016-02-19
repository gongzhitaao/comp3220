TEXI2PDF = texi2pdf
FLAGS = -c -p
cur := "$(shell find . -name \*.tex -mmin -1)"
cur := "$(shell basename $(cur))"

all : recent

recent :
	$(TEXI2PDF) $(FLAGS) $(cur)

.PHONY : all
