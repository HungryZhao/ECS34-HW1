CXX       := g++
SRC_DIR   := src
TEST_DIR  := testsrc
INC_DIR   := include

BINDIR    := bin
OBJDIR    := obj
TESTBINDIR:= testbin
TESTOBJDIR:= testobj
LIBDIR    := lib
HTMLCOV   := htmlcov
HTMLCONV  := htmlconv

TARGET    := $(TESTBINDIR)/teststrutils

CXXFLAGS  := -std=c++17 -Wall -Wextra -Wpedantic -g
CPPFLAGS  := -I$(INC_DIR)
LDFLAGS   :=
LDLIBS    :=

GTEST_CFLAGS := $(shell pkg-config --cflags gtest 2>/dev/null)
GTEST_LIBS   := $(shell pkg-config --libs gtest 2>/dev/null)
GTEST_MAIN_LIBS := $(shell pkg-config --libs gtest_main 2>/dev/null)

ifneq ($(strip $(GTEST_LIBS)),)
  CPPFLAGS += $(GTEST_CFLAGS)
	LDLIBS   += $(GTEST_LIBS)
	ifneq ($(strip $(GTEST_MAIN_LIBS)),)
		LDLIBS += $(GTEST_MAIN_LIBS)
	else
		LDLIBS += -lgtest_main
	endif
	LDLIBS   += -pthread
else
  LDLIBS   += -lgtest -lgtest_main -pthread
endif

SRCS      := $(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/*.cpp)
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cc $(TEST_DIR)/*.cpp)

OBJS      := $(patsubst $(SRC_DIR)/%.cc,$(OBJDIR)/%.o,$(filter %.cc,$(SRCS))) \
             $(patsubst $(SRC_DIR)/%.cpp,$(OBJDIR)/%.o,$(filter %.cpp,$(SRCS)))

TEST_OBJS := $(patsubst $(TEST_DIR)/%.cc,$(TESTOBJDIR)/%.o,$(filter %.cc,$(TEST_SRCS))) \
             $(patsubst $(TEST_DIR)/%.cpp,$(TESTOBJDIR)/%.o,$(filter %.cpp,$(TEST_SRCS)))

DIRS := $(BINDIR) $(OBJDIR) $(TESTBINDIR) $(TESTOBJDIR) $(LIBDIR) $(HTMLCOV) $(HTMLCONV)


CONV_INPUTS := $(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/*.cpp $(INC_DIR)/*.h $(TEST_DIR)/*.cc $(TEST_DIR)/*.cpp)
CONV_OUTPUTS := $(addprefix $(HTMLCONV)/,$(addsuffix .html,$(subst /,_,$(CONV_INPUTS))))

.PHONY: all
all: test htmlconv


define CONV_template
$(HTMLCONV)/$(subst /,_,$(1)).html: $(1) | $(HTMLCONV)
	pygmentize -f html -O full -o $$@ $$<
endef

$(foreach f,$(CONV_INPUTS),$(eval $(call CONV_template,$(f))))

$(DIRS):
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRC_DIR)/%.cc | $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(TESTOBJDIR)/%.o: $(TEST_DIR)/%.cc | $(TESTOBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(TESTOBJDIR)/%.o: $(TEST_DIR)/%.cpp | $(TESTOBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS) $(TEST_OBJS) | $(TESTBINDIR)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)

.PHONY: test
test: $(TARGET)
	@echo "Running: $(TARGET)"
	@$(TARGET)

.PHONY: htmlconv
htmlconv: $(CONV_OUTPUTS)
	@echo "HTML: $(HTMLCONV)/"

.PHONY: coverage
coverage: | $(HTMLCOV) $(HTMLCONV)
	@echo "Coverage test"
	@$(MAKE) clean
	@$(MAKE) CXXFLAGS="$(CXXFLAGS) -O0 --coverage" LDFLAGS="--coverage" test
	@lcov -c -d . -o coverage.info
	@lcov --remove coverage.info '/usr/*' '*/$(TEST_DIR)/*' -o coverage.info
	@genhtml coverage.info -o $(HTMLCOV)
	@echo "Coverage HTML: $(HTMLCOV)/index.html"

.PHONY: clean
clean:
	@rm -rf $(BINDIR) $(OBJDIR) $(TESTBINDIR) $(TESTOBJDIR) $(HTMLCOV) $(HTMLCONV) $(LIBDIR)
	@rm -f coverage.info
	@find . -name "*.gcda" -o -name "*.gcno" | xargs -r rm -f
