all : robustness.pdf

.PHONY : all clean

robustness.pdf : robustness.tex 
	pdflatex -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true -dMaxSubsetPct=100 -dCompatibilityLevel=1.4 $^
	pdflatex -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true -dMaxSubsetPct=100 -dCompatibilityLevel=1.4 $^


clean :
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.toc

