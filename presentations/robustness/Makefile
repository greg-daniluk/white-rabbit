all : robustness.pdf

.PHONY : all clean

robustness.pdf : robustness.tex 
	pdflatex $^
	pdflatex $^

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc *.snm *.nav *~

