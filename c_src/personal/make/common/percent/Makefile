objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# foo.o: foo.c
# bar.o: bar.c
# all.o: all.c

# Syntax - targets ...: target-pattern: prereq-patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and set the "stem" to be "foo".
# It then replaces the '%' in prereq-patterns with that stem
$(objects): %.o: %.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
