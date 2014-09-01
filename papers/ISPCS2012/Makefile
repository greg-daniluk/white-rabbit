all : WhiteRabbit.pdf

.PHONY : all clean

WhiteRabbit.pdf : WhiteRabbit.tex 
	latex $^
	bibtex WhiteRabbit
	latex $^
	latex $^
	dvips WhiteRabbit
	ps2pdf  -dPDFX -dEmbedAllFonts=true -dSubsetFonts=true -dEPSCrop=true WhiteRabbit.ps

clean :
#	$(MAKE) clean -C fig 
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *~ *.blg *.bbl

