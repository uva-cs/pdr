CXX=clang++ -O2
OFILES=List.o ListItr.o ListNode.o ListTest.o

.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(OFILES)

List.o: List.cpp List.h ListNode.cpp ListNode.h ListItr.cpp ListItr.h

ListItr.o: ListItr.cpp ListItr.h ListNode.cpp ListNode.h List.cpp List.h

ListNode.o: ListNode.cpp ListNode.h

clean:
	-rm -f *.o *~ a.out
