all : robustness.pdf

.PHONY : all clean

robustness.pdf : robustness.tex figs
	latex $^
	latex $^
	dvips robustness
	ps2pdf robustness.ps

figs:
	$(MAKE) -C fig

clean :
	$(MAKE) clean -C fig 
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps

