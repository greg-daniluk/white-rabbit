all : wr_efts_07_2014.pdf

.PHONY : all clean

wr_efts_07_2014.pdf : wr_efts_07_2014.tex
	pdflatex $^
	pdflatex $^

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.nav *.snm *.toc

