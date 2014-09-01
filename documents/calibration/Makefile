all : wrcalib.pdf

.PHONY : all clean

wrcalib.pdf : wrcalib.tex
	latex $^
	latex $^
	dvips wrcalib
	ps2pdf -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true -dMaxSubsetPct=100 -dCompatibilityLevel=1.4 wrcalib.ps

clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc

