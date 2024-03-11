obj_files = foo.result bar.o lose.o
src_files = foo.raw bar.c lose.c

all: $(obj_files)
	# Note: PHONY is important here. Without it, implicit rules will try to buld the executable "all", since the prereqs are ".o" files.
.PHONY: all

# Filter out all the .o files
# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
# $< : the first prerequisite
$(filter %.o, $(obj_files)): %.o: %.c
	echo "target: $@ prereq: $<"

# Ex 2: .result files depend on .raw files. Though we don't actually make the .result file.
$(filter %.result, $(obj_files)): %.result: %.raw
	echo "target: $@ prereq: $<"

%.c %.raw:
	touch $@

clean:
	rm -f $(src_files)
