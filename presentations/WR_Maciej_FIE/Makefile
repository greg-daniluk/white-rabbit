all : WhiteRabbit.pdf

.PHONY : all clean

WhiteRabbit.pdf : WhiteRabbit.tex 
	pdflatex $^
	pdflatex $^

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc *.snm *.nav *~

