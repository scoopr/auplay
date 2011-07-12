
OBJS=main.o AudioPlayer.o

CPPFLAGS+=
LDFLAGS+=-framework CoreFoundation -framework AudioToolbox

test: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@



.PHONY: clean
clean:
	$(RM) $(OBJS)


