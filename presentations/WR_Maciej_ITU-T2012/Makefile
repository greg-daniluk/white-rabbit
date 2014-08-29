all : WhiteRabbit.pdf

.PHONY : all clean

WhiteRabbit.pdf : WhiteRabbit.tex
	latex $^
	latex $^
	dvips WhiteRabbit

	ps2pdf WhiteRabbit.ps

clean :
#	$(MAKE) clean -C fig 
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.nav *.snm *.toc

