#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
  REQUIRE(true == true);
}

TEST_CASE("Test gc_content function") {
  std::string strand{"AGCTATAG"};
  REQUIRE(get_gc_content(strand) == 0.375);
  std::string strand0{"CGCTATAG"};
  REQUIRE(get_gc_content(strand0) == 0.5);
}

TEST_CASE("Test get_reverse_string function") {
  std::string to_reverse{"AGCTATAG"};
  REQUIRE(get_reverse_string(to_reverse) == "GATATCGA");
  std::string to_reverse1{"CGCTATAG"};
  REQUIRE(get_reverse_string(to_reverse1) == "GATATCGC");
  std::string to_reverse2{"AAAACCCGGT"};
  REQUIRE(get_reverse_string(to_reverse2) == "TGGCCCAAAA");
}

TEST_CASE("Test get_dna_complement function") {
  std::string dna_strand{"AAAACCCGGT"};
  REQUIRE(get_dna_complement(dna_strand) == "ACCGGGTTTT");
  std::string dna_strand1{"CCCGGAAAAT"};
  REQUIRE(get_dna_complement(dna_strand1) == "ATTTTCCGGG");
}