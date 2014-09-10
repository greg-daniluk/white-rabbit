all : robustness.pdf

.PHONY : all clean

robustness.pdf : robustness.tex
	latex $^
	latex $^
	dvips robustness
	ps2pdf robustness.ps

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.nav *.snm *.toc

