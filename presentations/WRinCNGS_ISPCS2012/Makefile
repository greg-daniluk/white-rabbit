all : WhiteRabbit.pdf

.PHONY : all clean

WhiteRabbit.pdf : WhiteRabbit.tex 
	latex $^
	latex $^
	dvips WhiteRabbit

	ps2pdf WhiteRabbit.ps

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc *.snm *.nav *~

