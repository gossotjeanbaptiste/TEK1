CC = gcc
CFLAGS = -Wall -Wextra -I../include
LDFLAGS = -L.. -lcuddle -lm

TESTS = test_read_write test_head test_tail test_shape test_info test_describe \
        test_filter test_sort test_groupby test_apply test_to_type \
		test_custom_separator test_mean_calculation test_memory_management \
		test_separators

all: $(TESTS)

test_read_write: test_read_write.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_head: test_head.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_tail: test_tail.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_shape: test_shape.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_info: test_info.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_describe: test_describe.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_filter: test_filter.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_sort: test_sort.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_groupby: test_groupby.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_apply: test_apply.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_to_type: test_to_type.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_custom_separator: test_custom_separator.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_mean_calculation: test_mean_calculation.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_memory_management: test_memory_management.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test_separators: test_separators.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

run: all
	@echo "Running all tests..."
	@for test in $(TESTS); do \
		echo "\n=== Running $$test ==="; \
		./$$test; \
	done

clean:
	rm -f $(TESTS) *.csv

.PHONY: all run clean