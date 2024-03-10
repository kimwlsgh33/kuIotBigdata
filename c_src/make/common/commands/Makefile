SHELL=/opt/homebrew/bin/fish

all:
	@echo "This make line will not be printed"
	echo "But this will"

	cd ..
	# The cd above does not affect this line, because each command is effectively run in a new shell
	echo `pwd`

	# This cd commands affects the next because they are on the same line
	cd ..;echo `pwd`

	# Same as above
	cd ..; \
	echo `pwd`

cool:
	@echo "Echo from fish"
