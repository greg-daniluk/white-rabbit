all : WhiteRabbit.pdf

.PHONY : all clean

WhiteRabbit.pdf : WhiteRabbit.tex 
	pdflatex -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true -dMaxSubsetPct=100 -dCompatibilityLevel=1.4 $^
	bibtex WhiteRabbit
	pdflatex -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true -dMaxSubsetPct=100 -dCompatibilityLevel=1.4 $^
	pdflatex -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true -dMaxSubsetPct=100 -dCompatibilityLevel=1.4 $^

clean :
#	$(MAKE) clean -C fig 
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *~ *.blg *.bbl

