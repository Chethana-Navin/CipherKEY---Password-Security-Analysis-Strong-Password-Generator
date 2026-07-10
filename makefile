# Compiler
CC = gcc


# Compiler flags
CFLAGS = -Wall -Wextra


# Source directory
SRC = src


# Output file
TARGET = CipherKey



# All source files

FILES = \
$(SRC)/main.c \
$(SRC)/password_checker.c \
$(SRC)/password_generator.c \
$(SRC)/entropy_calculator.c \
$(SRC)/crack_time_estimator.c \
$(SRC)/common_password_checker.c \
$(SRC)/password_analyzer.c \
$(SRC)/password_input.c \
$(SRC)/keyboard_pattern_checker.c \
$(SRC)/strength_meter.c \
$(SRC)/report_exporter.c



# Build program

$(TARGET):
	$(CC) $(FILES) $(CFLAGS) -o $(TARGET) -lm



# Run program

run:
	./$(TARGET)



# Clean generated files

clean:
	rm -f $(TARGET)