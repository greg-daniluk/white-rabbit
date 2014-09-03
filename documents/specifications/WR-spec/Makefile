all : wrspec.pdf

.PHONY : all clean

wrspec.pdf : wrspec.tex
	latex $^
	latex $^
	dvips wrspec
	ps2pdf wrspec.ps

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc

