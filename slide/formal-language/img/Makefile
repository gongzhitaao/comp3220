TEXI2PDF = texi2pdf
FLAGS = -c -p

# find the most recently changed tex file in 1 minute
cur := "$(shell find . -name \*.tex -mmin -1)"
cur := "$(shell basename $(cur))"

all : recent

recent :
	$(TEXI2PDF) $(FLAGS) $(cur)

.PHONY : all
