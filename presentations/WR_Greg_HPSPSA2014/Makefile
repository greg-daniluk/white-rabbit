all : WhiteRabbit_joburg.pdf

.PHONY : all clean

WhiteRabbit_joburg.pdf : WhiteRabbit_joburg.tex
	pdflatex $^
	pdflatex $^

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc *.snm *.nav *~

