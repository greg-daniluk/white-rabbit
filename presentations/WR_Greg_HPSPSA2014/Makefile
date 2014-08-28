all : WhiteRabbit_joburg.pdf

.PHONY : all clean

WhiteRabbit_joburg.pdf : WhiteRabbit_joburg.tex
	latex $^
	latex $^
	dvips WhiteRabbit_joburg

	ps2pdf WhiteRabbit_joburg.ps

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc *.snm *.nav *~

