all : switch_hdl.pdf

.PHONY : all clean

switch_hdl.pdf : switch_hdl.tex
	latex $^
	latex $^
	dvips switch_hdl
	ps2pdf switch_hdl.ps

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc

