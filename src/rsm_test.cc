#include "raglib/rsm.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <kaitai/exceptions.h>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace {

const std::filesystem::path kTestDataPath(RAGLIB_TEST_DATA_PATH);

TEST(Rsm, CtorEmptyData) {
  std::istringstream is("");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::rsm_t rsm(&ks), std::ios_base::failure);
}

TEST(Rsm, CtorInvalidData) {
  std::istringstream is("Not an RSM file");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::rsm_t rsm(&ks), kaitai::kstruct_error);
}

TEST(Rsm, CtorValidRsm104Controller) {
  const auto file_path = kTestDataPath / "rsm" / "104-controller.rsm";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::rsm_t rsm(&ks);
  EXPECT_EQ(rsm.version(), 0x104);
  EXPECT_EQ(rsm.texture_count(), 2);
  EXPECT_STREQ(rsm.main_node_name().c_str(), "borf");
  EXPECT_EQ(rsm.animation_count(), 16000);
  EXPECT_EQ(rsm.shading_type(), raglib::rsm_t::shading_t::SHADING_FLAT);
  EXPECT_EQ(rsm.alpha(), 255);
  EXPECT_EQ(rsm.node_count(), 1);
  EXPECT_EQ(rsm.pos_key_count(), 0);
  EXPECT_EQ(rsm.volume_box_count(), 0);
  // Textures
  const auto& texture_name_0 = (*rsm.texture_names())[0];
  EXPECT_STREQ(texture_name_0.c_str(), "kitchen\\garbage.bmp");
  const auto& texture_name_1 = (*rsm.texture_names())[1];
  EXPECT_STREQ(texture_name_1.c_str(), "kitchen\\colors.bmp");
  // Nodes
  const auto& p_node = (*rsm.nodes())[0];
  EXPECT_EQ(p_node->face_count(), 5652);
  EXPECT_EQ(p_node->node_vertex_count(), 4764);
  EXPECT_EQ(p_node->texture_vertex_count(), 4764);
  EXPECT_EQ(p_node->texture_count(), 2);
}

TEST(Rsm, CtorValidRsm104Pokercenter) {
  const auto file_path = kTestDataPath / "rsm" / "104-pokecenter.rsm";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::rsm_t rsm(&ks);
  EXPECT_EQ(rsm.version(), 0x104);
  EXPECT_EQ(rsm.texture_count(), 1);
  EXPECT_STREQ(rsm.main_node_name().c_str(), "borf");
  EXPECT_EQ(rsm.animation_count(), 16000);
  EXPECT_EQ(rsm.shading_type(), raglib::rsm_t::shading_t::SHADING_FLAT);
  EXPECT_EQ(rsm.alpha(), 255);
  EXPECT_EQ(rsm.node_count(), 1);
  EXPECT_EQ(rsm.pos_key_count(), 0);
  EXPECT_EQ(rsm.volume_box_count(), 0);
  // Textures
  const auto& texture_name = (*rsm.texture_names())[0];
  EXPECT_STREQ(texture_name.c_str(), "pokemon\\pokecentre.bmp");
  // Nodes
  const auto& p_node = (*rsm.nodes())[0];
  EXPECT_EQ(p_node->face_count(), 1308);
  EXPECT_EQ(p_node->node_vertex_count(), 1608);
  EXPECT_EQ(p_node->texture_vertex_count(), 1608);
  EXPECT_EQ(p_node->texture_count(), 1);
}

}  // namespace