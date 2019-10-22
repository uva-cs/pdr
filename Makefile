markdown:
	@echo Converting markdown files to html format...
	@chmod 755 utils/convert-markdown-to-html
	@utils/convert-markdown-to-html
	@git checkout uva/old/*.html
	@echo done!

format:
	@echo Formatting source files...
	@chmod 755 utils/format-source-files
	@utils/format-source-files
	@git checkout uva/old/*.html
	@echo done!

clean:
	/bin/rm -rf *~ */*~ */*/*~ */*/*/*~
	/bin/rm -f uva/*.aux uva/*.log

source-highlight:
	source-highlight -d labs/*/*.cpp labs/*/*.h labs/*/*/*.cpp labs/*/*/*.h labs/*/*/*/*.cpp labs/*/*/*/*.h tutorials/*/*.cpp
