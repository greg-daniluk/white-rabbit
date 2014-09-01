THBL2.pdf : THBL2.ps
	ps2pdf -dEmbedAllFonts=true THBL2.ps THBL2.pdf

THBL2.ps : THBL2.dvi
	dvips THBL2.dvi -j0-D600 -o THBL2.ps

THBL2.dvi: THBL2.tex
	latex THBL2.tex
	latex THBL2.tex

clean:
	rm *.aux *.dvi *.log *.pdf *.ps
