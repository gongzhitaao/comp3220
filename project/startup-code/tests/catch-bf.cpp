#include <string>
#include <cstdint>
#include <functional>

#include "catch.hpp"
#include "bf.h"

TEST_CASE("Edge cases", "[bf][edge-case]") {
  BF bf;
  bytestream is, os;

  SECTION("pointer underflow") {
    std::string src("<");

    REQUIRE(bf.interpret(src, is, os));
    REQUIRE(bf.ptr() == BF::MEM_SIZE - 1);
  }

  SECTION("pointer overflow") {
    std::string src(BF::MEM_SIZE, '>');

    REQUIRE(bf.interpret(src, is, os));
    REQUIRE(bf.ptr() == 0);
  }

  SECTION("memory byte underflow") {
    std::string src("-.");

    REQUIRE(bf.interpret(src, is, os));

    uint8_t v;
    os.read(&v, 1);
    REQUIRE(v == UINT8_MAX);
  }

  SECTION("memory byte overflow") {
    std::string src('+', UINT8_MAX);
    src += "+.";

    REQUIRE(bf.interpret(src, is, os));

    uint8_t v;
    os.read(&v, 1);
    REQUIRE(0 == v);
  }
}

TEST_CASE("Unbalanced bracket", "[bf][unbalanced-bracket]") {
  BF bf;
  std::string src;
  bytestream is, os;

  src = "[";
  REQUIRE(!bf.interpret(src, is, os));

  src = "[[]";
  REQUIRE(!bf.interpret(src, is, os));

  src = "]";
  REQUIRE(!bf.interpret(src, is, os));

  src = "[+";
  REQUIRE(!bf.interpret(src, is, os));

  src = "-[";
  REQUIRE(!bf.interpret(src, is, os));
}

TEST_CASE("Ignore unrecognized operations", "[bf][ignore-other]") {
  BF bf;
  std::string src;
  bytestream is, os;

  src = "a";
  REQUIRE(bf.interpret(src, is, os));

  src = "123";
  REQUIRE(bf.interpret(src, is, os));

  SECTION("with output") {
    src = "a+.";
    REQUIRE(bf.interpret(src, is, os));

    uint8_t v;
    os.read(&v, 1);
    REQUIRE(v == 1);
  }

  SECTION("with output") {
    src = "+8.";
    REQUIRE(bf.interpret(src, is, os));

    uint8_t v;
    os.read(&v, 1);
    REQUIRE(v == 1);
  }

  SECTION("with output") {
    src = "+.$";
    REQUIRE(bf.interpret(src, is, os));

    uint8_t v;
    os.read(&v, 1);
    REQUIRE(v == 1);
  }

  SECTION("with input and output") {
    src = ",$.";
    uint8_t in = 3;
    is.write(&in, 1);
    REQUIRE(bf.interpret(src, is, os));

    uint8_t out;
    os.read(&out, 1);
    REQUIRE(in == out);
  }
}

TEST_CASE("Normal parsing", "[bf][normal]") {
  BF bf;
  std::string src;
  bytestream is, os;

  SECTION("input and output") {
    src = ",.";

    uint8_t in = 3;
    is.write(&in, 1);
    REQUIRE(bf.interpret(src, is, os));

    uint8_t out;
    os.read(&out, 1);
    REQUIRE(in == out);
  }
}
