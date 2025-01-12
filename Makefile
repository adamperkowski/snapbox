# snapbox
# HTTP Client Library for Jule
# https://github.com/adamperkowski/snapbox
# Copyright (c) 2025, Adam Perkowski
# BSD 3-Clause License

JULEC = julec
JULEFMT = julefmt

NAME = snapbox
MODULES = status header
EXAMPLES = simpleGET

examples:
	mkdir -p examples/bin
	@for example in $(EXAMPLES); do \
		cd examples/$$example; \
		echo "Building $$example..."; \
		$(JULEC) . -o ../bin/$$example; \
		cd ../..; \
	done

format:
	$(JULEFMT) -w $(NAME)
	@for module in $(MODULES); do \
		$(JULEFMT) -w $(NAME)/$$module; \
	done
	@for example in $(EXAMPLES); do \
		$(JULEFMT) -w examples/$$example; \
	done

test:
	mkdir -p bin
	$(JULEC) test $(NAME) -o bin/$(NAME)
	./bin/$(NAME)
	@for module in $(MODULES); do \
		echo "Testing $(NAME)/$$module..."; \
		$(JULEC) test $(NAME)/$$module -o bin/$$module; \
		./bin/$$module; \
	done

clean:
	rm -rf bin examples/bin

.PHONY: examples format test clean
