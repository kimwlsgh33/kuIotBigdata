# Problems

If we modify the source code, Makefile doesn't get updated.

- [Makefile](./Makefile)
- [blah.c](./blah.c)

# Solution

The make uses **the filesystem timestamps** as a proxy to determine if something has changed.

But, this **is not** always the case. (old timestamps of files could be ignored)
