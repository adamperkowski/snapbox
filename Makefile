# snapbox
# HTTP Client Library for Jule
# https://github.com/adamperkowski/snapbox
# Copyright (c) 2025, Adam Perkowski
# BSD 3-Clause License

JULEC = julec
JULEFMT = julefmt
JULEDOC = juledoc

NAME = snapbox
MODULES = status header
EXAMPLES = simpleGET simpleHEAD simplePOST simplePUT simpleDELETE simpleDownload
LIB = $(NAME).jule $(MODULES) internal jule.mod LICENSE README.md

examples:
	mkdir -p examples/bin
	@for example in $(EXAMPLES); do \
		cd examples/$$example; \
		echo "Building $$example..."; \
		$(JULEC) . -o ../bin/$$example; \
		cd ../..; \
	done

run-examples: examples
	echo
	@for example in $(EXAMPLES); do \
		echo -e "Running $$example..."; \
		./examples/bin/$$example $(TESTARGS); \
		echo; \
	done

format:
	$(JULEFMT) -w .
	@for module in $(MODULES); do \
		$(JULEFMT) -w $$module; \
	done
	@for example in $(EXAMPLES); do \
		$(JULEFMT) -w examples/$$example; \
	done

test:
	mkdir -p bin
	$(JULEC) test . -o bin/$(NAME)
	./bin/$(NAME)
	@for module in $(MODULES); do \
		echo "Testing $(NAME)/$$module..."; \
		$(JULEC) test $$module -o bin/$$module; \
		./bin/$$module; \
	done

doc:
	sed -i '/# API Reference/,$$d' book/src/SUMMARY.md;
	echo '# API Reference' >> book/src/SUMMARY.md;
	$(JULEDOC) . > book/src/api/$(NAME).md;
	echo "- [$(NAME)](./api/$(NAME).md)" >> book/src/SUMMARY.md;
	@for module in $(MODULES); do \
		$(JULEDOC) $$module > book/src/api/$$module.md; \
		echo "- [$(NAME)/$$module](./api/$$module.md)" >> book/src/SUMMARY.md; \
	done
package:
	mkdir -p $(NAME)
	cp -R $(LIB) $(NAME)
	tar -czf $(NAME)-$(VERSION).tar.gz $(NAME)
	zip -r $(NAME)-$(VERSION).zip $(NAME)

clean:
	rm -rf bin examples/bin $(NAME) *.tar.gz *.zip

.PHONY: examples format test clean
