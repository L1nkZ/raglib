#include "raglib/act.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <kaitai/exceptions.h>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>

namespace {

using testing::ContainerEq;

const std::filesystem::path kTestDataPath(RAGLIB_TEST_DATA_PATH);

TEST(Act, CtorEmptyData) {
  std::string content("");
  kaitai::kstream ks(content);
  EXPECT_THROW(const raglib::act_t act(&ks), std::ios_base::failure);
}

TEST(Act, CtorInvalidData) {
  std::string content("Not an ACT file");
  kaitai::kstream ks(content);
  EXPECT_THROW(const raglib::act_t act(&ks), kaitai::kstruct_error);
}

TEST(Act, CtorValidAct205DarkMoon) {
  const auto file_path = kTestDataPath / "act" / "205-dark-moon.act";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::act_t act(&ks);

  EXPECT_EQ(act.version(), 0x205);
  EXPECT_EQ(act.action_count(), 8);
  EXPECT_EQ(act.sound_file_count(), 0);
  EXPECT_EQ(act.animation_speeds()->size(), 8);

  const auto& actions = *act.actions();
  EXPECT_EQ(actions[actions.size() - 1]->frame_count(), 16);

  const auto& frames = *actions[actions.size() - 1]->frames();
  auto last_frame = frames[frames.size() - 1];
  EXPECT_EQ(last_frame->sound_id(), -1);
  EXPECT_EQ(last_frame->layer_count(), 3);
  EXPECT_EQ(last_frame->anchor_count(), 0);

  const auto& layers = *last_frame->layers();
  auto last_layer = layers[layers.size() - 1];
  EXPECT_THAT(*last_layer->position(),
              ContainerEq(std::vector<int>({39, -88})));
  EXPECT_EQ(last_layer->index(), 2);
  EXPECT_EQ(last_layer->is_mirror(), 0);
  EXPECT_THAT(*last_layer->color(),
              ContainerEq(std::vector<uint8_t>({255, 255, 255, 255})));
  EXPECT_EQ(last_layer->scale_x(), 1);
  EXPECT_EQ(last_layer->scale_y(), 1);
  EXPECT_EQ(last_layer->angle(), 0);
  EXPECT_EQ(last_layer->spr_type(), 0);
  EXPECT_EQ(last_layer->width(), 45);
  EXPECT_EQ(last_layer->height(), 47);
}

TEST(Act, CtorValidAct205WeirdBox) {
  const auto file_path = kTestDataPath / "act" / "205-weird-box.act";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::act_t act(&ks);

  EXPECT_EQ(act.version(), 0x205);
  EXPECT_EQ(act.action_count(), 8);
  EXPECT_EQ(act.sound_file_count(), 0);
  EXPECT_EQ(act.animation_speeds()->size(), 8);

  const auto& actions = *act.actions();
  EXPECT_EQ(actions[actions.size() - 1]->frame_count(), 3);

  const auto& frames = *actions[actions.size() - 1]->frames();
  auto last_frame = frames[frames.size() - 1];
  EXPECT_EQ(last_frame->sound_id(), -1);
  EXPECT_EQ(last_frame->layer_count(), 1);
  EXPECT_EQ(last_frame->anchor_count(), 0);

  const auto& layers = *last_frame->layers();
  auto last_layer = layers[layers.size() - 1];
  EXPECT_THAT(*last_layer->position(), ContainerEq(std::vector<int>({2, -20})));
  EXPECT_EQ(last_layer->index(), 2);
  EXPECT_EQ(last_layer->is_mirror(), 0);
  EXPECT_THAT(*last_layer->color(),
              ContainerEq(std::vector<uint8_t>({255, 255, 255, 255})));
  EXPECT_EQ(last_layer->scale_x(), 1);
  EXPECT_EQ(last_layer->scale_y(), 1);
  EXPECT_EQ(last_layer->angle(), 0);
  EXPECT_EQ(last_layer->spr_type(), 1);
  EXPECT_EQ(last_layer->width(), 73);
  EXPECT_EQ(last_layer->height(), 75);
}

}  // namespace