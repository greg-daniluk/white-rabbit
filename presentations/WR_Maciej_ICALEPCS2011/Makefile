all : WhiteRabbit.pdf

.PHONY : all clean

WhiteRabbit.pdf : WhiteRabbit.tex
	pdflatex $^
	pdflatex $^

clean :
#	$(MAKE) clean -C fig 
	rm -f *.eps *.pdf *.dat *.log *.out *.aux *.dvi *.ps *.nav *.snm *.toc

