#include <Arduino.h>
#include <M5StickCPlus2.h>


//*  // color
static constexpr const uint32_t color_table[] = {
0x0000FFu,0x0003FFu,0x0006FFu,0x0009FFu,0x000CFFu,0x000FFFu,0x0012FFu,0x0016FFu,
0x0019FEu,0x001CFEu,0x001FFEu,0x0022FDu,0x0025FDu,0x0028FCu,0x002BFCu,0x002FFBu,
0x0032FBu,0x0035FAu,0x0038F9u,0x003BF9u,0x003EF8u,0x0041F7u,0x0044F6u,0x0047F6u,
0x004AF5u,0x004DF4u,0x0050F3u,0x0053F2u,0x0056F1u,0x0059F0u,0x005CEFu,0x005FEEu,
0x0062ECu,0x0065EBu,0x0068EAu,0x006AE9u,0x006DE7u,0x0070E6u,0x0073E5u,0x0076E3u,
0x0079E2u,0x007BE0u,0x007EDFu,0x0081DDu,0x0084DCu,0x0086DAu,0x0089D8u,0x008CD7u,
0x008ED5u,0x0091D3u,0x0093D1u,0x0096CFu,0x0098CEu,0x009BCCu,0x009DCAu,0x00A0C8u,
0x00A2C6u,0x00A5C4u,0x00A7C2u,0x00AAC0u,0x00ACBEu,0x00AEBCu,0x00B1B9u,0x00B3B7u,
0x00B5B5u,0x00B7B3u,0x00B9B1u,0x00BCAEu,0x00BEACu,0x00C0AAu,0x00C2A7u,0x00C4A5u,
0x00C6A2u,0x00C8A0u,0x00CA9Du,0x00CC9Bu,0x00CE98u,0x00CF96u,0x00D193u,0x00D391u,
0x00D58Eu,0x00D78Cu,0x00D889u,0x00DA86u,0x00DC84u,0x00DD81u,0x00DF7Eu,0x00E07Bu,
0x00E279u,0x00E376u,0x00E573u,0x00E670u,0x00E76Du,0x00E96Au,0x00EA68u,0x00EB65u,
0x00EC62u,0x00EE5Fu,0x00EF5Cu,0x00F059u,0x00F156u,0x00F253u,0x00F350u,0x00F44Du,
0x00F54Au,0x00F647u,0x00F644u,0x00F741u,0x00F83Eu,0x00F93Bu,0x00F938u,0x00FA35u,
0x00FB32u,0x00FB2Fu,0x00FC2Bu,0x00FC28u,0x00FD25u,0x00FD22u,0x00FE1Fu,0x00FE1Cu,
0x00FE19u,0x00FF16u,0x00FF12u,0x00FF0Fu,0x00FF0Cu,0x00FF09u,0x00FF06u,0x00FF03u,
0x03FF00u,0x06FF00u,0x09FF00u,0x0CFF00u,0x0FFF00u,0x12FF00u,0x16FF00u,0x19FE00u,
0x1CFE00u,0x1FFE00u,0x22FD00u,0x25FD00u,0x28FC00u,0x2BFC00u,0x2FFB00u,0x32FB00u,
0x35FA00u,0x38F900u,0x3BF900u,0x3EF800u,0x41F700u,0x44F600u,0x47F600u,0x4AF500u,
0x4DF400u,0x50F300u,0x53F200u,0x56F100u,0x59F000u,0x5CEF00u,0x5FEE00u,0x62EC00u,
0x65EB00u,0x68EA00u,0x6AE900u,0x6DE700u,0x70E600u,0x73E500u,0x76E300u,0x79E200u,
0x7BE000u,0x7EDF00u,0x81DD00u,0x84DC00u,0x86DA00u,0x89D800u,0x8CD700u,0x8ED500u,
0x91D300u,0x93D100u,0x96CF00u,0x98CE00u,0x9BCC00u,0x9DCA00u,0xA0C800u,0xA2C600u,
0xA5C400u,0xA7C200u,0xAAC000u,0xACBE00u,0xAEBC00u,0xB1B900u,0xB3B700u,0xB5B500u,
0xB7B300u,0xB9B100u,0xBCAE00u,0xBEAC00u,0xC0AA00u,0xC2A700u,0xC4A500u,0xC6A200u,
0xC8A000u,0xCA9D00u,0xCC9B00u,0xCE9800u,0xCF9600u,0xD19300u,0xD39100u,0xD58E00u,
0xD78C00u,0xD88900u,0xDA8600u,0xDC8400u,0xDD8100u,0xDF7E00u,0xE07B00u,0xE27900u,
0xE37600u,0xE57300u,0xE67000u,0xE76D00u,0xE96A00u,0xEA6800u,0xEB6500u,0xEC6200u,
0xEE5F00u,0xEF5C00u,0xF05900u,0xF15600u,0xF25300u,0xF35000u,0xF44D00u,0xF54A00u,
0xF64700u,0xF64400u,0xF74100u,0xF83E00u,0xF93B00u,0xF93800u,0xFA3500u,0xFB3200u,
0xFB2F00u,0xFC2B00u,0xFC2800u,0xFD2500u,0xFD2200u,0xFE1F00u,0xFE1C00u,0xFE1900u,
0xFF1600u,0xFF1200u,0xFF0F00u,0xFF0C00u,0xFF0900u,0xFF0600u,0xFF0300u,0xFF0000u,
};
static constexpr const char* test_name[] = {
  "Button Clk",
  " Rate 64Hz",
  " Rate 32Hz",
  " Rate 16Hz",
  "Buzzer&Led",
  " Reg Write"
};
struct rect_t
{
  int16_t x;
  int16_t y;
  int16_t w;
  int16_t h;
  void set(int16_t x_, int16_t y_, int16_t w_, int16_t h_)
  {
    x = x_;
    y = y_;
    w = w_;
    h = h_;
  }
};
static rect_t camera_area;
enum check_list_t
{
  button_click,
  refresh_64Hz,
  refresh_32Hz,
  refresh_16Hz,
  buzzer_led,
  register_write,
  check_list_max,
};
struct value_avg_t {
  size_t exec(size_t src, size_t margin) {
    target = (target * 3 + src) / 4.0f;
    auto temp = current;
    int diff = roundf(target - temp);
    if (add || abs(diff) > margin)
    {
      add = (add + diff) / 4 + ((temp < target) ? 1 : -1);
      temp += add;
      current = temp;
    }
    return roundf(temp);
  }
  value_avg_t(float default_value) : target { default_value }, current { default_value } {}

private:
  int add = 0;
  float target = (24 + 64) << 7;
  float current = (24 + 64) << 7;
};

enum check_state_t
{
  unknown,
  progress,
  success,
  failed,
};
static uint8_t check_list[check_list_max] = {0};
static uint8_t check_prev[check_list_max] = {0};

static uint32_t frame_counter = 0;
static uint32_t fps = 0;

struct temperature_info_t
{
  uint16_t temp;
  uint8_t x;
  uint8_t y;
};
struct temp_data_t
{
  int8_t refresh_control;
  uint8_t subpage;
  uint16_t med_temp;
  uint16_t avg_temp;
  temperature_info_t diff_info;
  temperature_info_t min_info;
  temperature_info_t max_info;
  uint16_t data[16 * 24];
};
temp_data_t tempdatas[2];
int idx_recv = 0;
int idx_draw = 0;

static constexpr int i2c_addr = 0x32;
static uint8_t register_data[0x80] = {0};

void recvTask(void*)
{
  static constexpr uint32_t threshold_low = (0.0f + 64) * 128;
  static constexpr uint32_t threshold_high = (100.0f + 64) * 128;

  enum test_step_t
  {
    test_button_click,
    test_refresh_rate_64Hz,
    test_refresh_rate_32Hz,
    test_refresh_rate_16Hz,
    test_buzzer_led,
    test_register_write,
    test_max,
  };

  test_step_t test_step = test_button_click;
  uint32_t step_counter = 0;

  static constexpr uint8_t cmd[] =
  {
    0x32, (uint8_t)~0x32, // I2C_Addr
    0x04,        // function control
    0x07,        // refresh rate
    0x04,        // Filter level
    0,
    0,
    0,

    0xFF,                     // monitor size
    0b00000000,               // Temp Alert enabled
    (uint8_t)4800, 4800 >> 8, // buzzer freq
    128,                      // buzzer duty
    0x00, 0x04, 0x00,         // color
    0,0,0,0,0,0,0,0,

    (uint8_t)threshold_low, (uint8_t)(threshold_low >> 8),
    (uint8_t)4800, 4800 >> 8,
    5,
    0x00, 0x00, 0x08,
    0,0,0,0,0,0,0,0,

    (uint8_t)threshold_high, (uint8_t)(threshold_high >> 8),
    (uint8_t)4800, 4800 >> 8,
    5,
    0x08, 0x00, 0x00,
    0,0,0,0,0,0,0,0,
  };

  static constexpr uint32_t default_threshold_low = (0.0f + 64) * 128;
  static constexpr uint32_t default_threshold_high = (100.0f + 64) * 128;
  static constexpr uint32_t default_buzzer_freq = 4800;
  static constexpr uint8_t reg_default[] =
  {
    0, 0, 0, 0,
    0x90, 0x64, // DEVICE_ID
    0x01, 0x01, // FIRMWARE_VERSION
    0x32, (uint8_t)~0x32, // I2C_Addr
    0x04,        // function control
    0x05,        // refresh rate
    0x04,        // Filter level
    0,
    0,
    0,

    0xFF,                     // monitor size
    0b00000000,               // Temp Alert enabled
    (uint8_t)default_buzzer_freq, default_buzzer_freq >> 8, // buzzer freq
    128,                      // buzzer duty
    0x00, 0x04, 0x00,         // color
    0,0,0,0,0,0,0,0,

    (uint8_t)default_threshold_low, (uint8_t)(default_threshold_low >> 8),
    (uint8_t)default_buzzer_freq, default_buzzer_freq >> 8,
    5,                        // interval
    0x00, 0x00, 0x08,         // color
    0,0,0,0,0,0,0,0,

    (uint8_t)default_threshold_high, (uint8_t)(default_threshold_high >> 8),
    (uint8_t)default_buzzer_freq, default_buzzer_freq >> 8,
    5,                        // interval
    0x08, 0x00, 0x00,         // color
    0,0,0,0,0,0,0,0,
  };

  static constexpr uint8_t THERMAL2_REG_FUNCTION_CTRL = 0x0A;
  static constexpr uint8_t THERMAL2_REG_REFRESH_RATE = 0x0B;
  static constexpr uint8_t THERMAL2_REG_NOISE_FILTER = 0x0C;
  static constexpr uint8_t THERMAL2_REG_REFRESH_CTRL = 0x6E;

  uint32_t freq_i2c_default = 400000;
  uint32_t freq_i2c_read = 921600;
  for (;;)
  {
    StickCP2.update();

    // bool reader = StickCP2.Ex_I2C.readRegister(i2c_addr, 0x00, register_data, sizeof(register_data), freq_i2c_default);
    // Serial.println(reader ? "I2C Read OK" : "I2C Read Failed");
    // if (reader) {
    //   StickCP2.Ex_I2C.writeRegister8(i2c_addr, 0x15, 0x01, freq_i2c_default);
    //   StickCP2.Ex_I2C.writeRegister8(i2c_addr, 0x16, 0x0F, freq_i2c_default);
    //   StickCP2.Ex_I2C.writeRegister8(i2c_addr, 0x17, 0xFF, freq_i2c_default);
    //   // print register_data if register_data changed
    //   for (size_t i = 0; i < sizeof(register_data); ++i)
    //   {
    //     Serial.printf("%02X ", register_data[i]);
    //     if ((i & 15) == 15) Serial.println();
    //   }
    // }
    if (!StickCP2.Ex_I2C.readRegister(i2c_addr, 0x00, register_data, sizeof(register_data), 400000) || StickCP2.BtnA.wasClicked())
    {
      // memset(check_list, check_state_t::unknown, sizeof(check_list));
      // check_list[check_list_t::button_click] = check_state_t::progress;
      // test_step = test_button_click;
      // step_counter = 0;
      // StickCP2.Ex_I2C.writeRegister(i2c_addr, 0, reg_default, sizeof(reg_default), freq_i2c_default);
    } 
    // else if (register_data[0x00]) {
    //   StickCP2.Ex_I2C.writeRegister8(i2c_addr, 0, register_data[0x00], freq_i2c_default);
    // }

    // switch (test_step)
    // {
    // case test_button_click:
    //   if (register_data[0x00]) {
    //     auto rd = register_data[0x00];
    //     if (rd & 8) {
    //       check_list[check_list_t::button_click] = check_state_t::success;

    //       check_list[check_list_t::refresh_64Hz] = check_state_t::progress;
    //       test_step = test_refresh_rate_64Hz;
    //       step_counter = 0;

    //       StickCP2.Ex_I2C.writeRegister(i2c_addr, 0x08, cmd, sizeof(cmd), 400000);
    //       freq_i2c_read = 921600;
    //     }
    //   }
    //   break;

    // case test_refresh_rate_64Hz:
    //   if (++step_counter > 8192)
    //   {
    //     check_list[check_list_t::refresh_64Hz] = check_state_t::failed;
    //     test_step = test_button_click;
    //     break;
    //   }
    //   else if (fps >= 55 && fps <= 64) {
    //     check_list[check_list_t::refresh_64Hz] = check_state_t::success;

    //     check_list[check_list_t::refresh_32Hz] = check_state_t::progress;
    //     test_step = test_refresh_rate_32Hz;
    //     StickCP2.Ex_I2C.writeRegister8(i2c_addr, THERMAL2_REG_REFRESH_RATE, 6, freq_i2c_default);
    //     step_counter = 0;
    //     freq_i2c_read = 400000;
    //   }
    //   break;

    // case test_refresh_rate_32Hz:
    //   if (++step_counter > 8192)
    //   {
    //     check_list[check_list_t::refresh_32Hz] = check_state_t::failed;
    //     test_step = test_button_click;
    //     break;
    //   }
    //   else if (fps >= 31 && fps <= 32) {
    //     check_list[check_list_t::refresh_32Hz] = check_state_t::success;

    //     check_list[check_list_t::refresh_16Hz] = check_state_t::progress;
    //     test_step = test_refresh_rate_16Hz;
    //     StickCP2.Ex_I2C.writeRegister8(i2c_addr, THERMAL2_REG_REFRESH_RATE, 5, freq_i2c_default);
    //     step_counter = 0;
    //   }
    //   break;

    // case test_refresh_rate_16Hz:
    //   if (++step_counter > 8192)
    //   {
    //     check_list[check_list_t::refresh_16Hz] = check_state_t::failed;
    //     test_step = test_button_click;
    //     break;
    //   }
    //   else if (fps >= 15 && fps <= 16) {
    //     check_list[check_list_t::refresh_16Hz] = check_state_t::success;

    //     check_list[check_list_t::buzzer_led] = check_state_t::progress;
    //     test_step = test_buzzer_led;
    //     step_counter = 0;
    //     StickCP2.Ex_I2C.writeRegister8(i2c_addr, THERMAL2_REG_FUNCTION_CTRL, 7, freq_i2c_default);
    //   }
    //   break;

    // case test_buzzer_led:
    //   if ((step_counter++ & 63) == 0)
    //   {
    //     uint8_t reg_0x12[6] = { 0 };
    //     auto s = step_counter >> 6;
    //     uint_fast16_t freq = 4000 + (s * 200);
    //     reg_0x12[0] = (uint8_t)freq;
    //     reg_0x12[1] = (uint8_t)(freq >> 8);
    //     reg_0x12[2] = 0;
    //     if (s == 10) {
    //       step_counter = 0;
    //       check_list[check_list_t::buzzer_led] = check_state_t::success;

    //       check_list[check_list_t::register_write] = check_state_t::progress;
    //       test_step = test_register_write;
    //     } else {
    //       switch (s % 5) {
    //       default:
    //       case 0:
    //         reg_0x12[3] = 7;
    //         break;

    //       case 1:
    //         reg_0x12[4] = 7;
    //         break;

    //       case 2:
    //         reg_0x12[5] = 7;
    //         break;

    //       case 3:
    //         reg_0x12[3] = 4;
    //         reg_0x12[4] = 4;
    //         reg_0x12[5] = 4;
    //         break;

    //       case 4:
    //         break;
    //       }
    //     }
    //     StickCP2.Ex_I2C.writeRegister(i2c_addr, 0x12, reg_0x12, sizeof(reg_0x12), freq_i2c_default);
    //   }
    //   else {
    //     uint8_t reg_0x14 = ((step_counter-1) & 63) * 4;
    //     StickCP2.Ex_I2C.writeRegister8(i2c_addr, 0x14, reg_0x14, freq_i2c_default);
    //   }
    //   break;

    // case test_register_write:
    //   if (step_counter++) {
    //     if (memcmp(register_data, reg_default, sizeof(reg_default))) {
    //       check_list[check_list_t::register_write] = check_state_t::failed;
    //       test_step = test_button_click;
    //       break;
    //     } else if (step_counter > 10) {
    //       check_list[check_list_t::register_write] = check_state_t::success;
    //       test_step = test_button_click;
    //       break;
    //     }
    //   }
    //   StickCP2.Ex_I2C.writeRegister(i2c_addr, 0, reg_default, sizeof(reg_default), freq_i2c_default);
    //   break;

    // default:
    //   break;
    // }

    uint8_t send_data[2] = { THERMAL2_REG_REFRESH_CTRL, 2 };
    if (StickCP2.Ex_I2C.start(i2c_addr, false, freq_i2c_default)
     && StickCP2.Ex_I2C.write(send_data, 1)
     && StickCP2.Ex_I2C.restart(i2c_addr, true, freq_i2c_read)
     && StickCP2.Ex_I2C.read((uint8_t*)&tempdatas[idx_recv], 1)
     && tempdatas[idx_recv].refresh_control & 1) // has_new data none
    {
      if (StickCP2.Ex_I2C.read(&((uint8_t*)&tempdatas[idx_recv])[1], sizeof(temp_data_t)-1))
      {
        idx_draw = idx_recv;
        idx_recv = !idx_recv;
      }
    }
    else
    {
      vTaskDelay(1);
    }
    StickCP2.Ex_I2C.stop();
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("=== M5StickCPlus2 Starting ===");
  
  // Use StickCP2 for your device
  auto cfg = M5.config();
  StickCP2.begin(cfg);
  StickCP2.Ex_I2C.begin();  // This is the key missing initialization!
  
  StickCP2.Display.setBrightness(10);
  
  int_fast16_t width = StickCP2.Display.width();
  int_fast16_t height = StickCP2.Display.height();
  camera_area.set(0, 0, 135, 100);
  
  xTaskCreatePinnedToCore(recvTask, "recvTask", 8192, NULL, 5, NULL, PRO_CPU_NUM);
}

void drawThermalImage() {
  static int idx_prev = -1;
  if (idx_prev == idx_draw) return;
  idx_prev = idx_draw;

  // Use idx_draw for even columns, !idx_draw for odd columns
  static int16_t values[32*24];
  temp_data_t* tempdata = &tempdatas[idx_prev];

  static value_avg_t min_avg = { (16 + 64) << 8 };
  static value_avg_t max_avg = { (48 + 64) << 8 };

  /// Sum of values for 2 frames
  static uint32_t min_sum = 0;
  static uint32_t max_sum = 0;
  static uint32_t avg_sum = 0;
  static uint32_t med_sum = 0;

  static uint32_t min_subpage = 0;
  static uint32_t max_subpage = 0;
  static uint32_t avg_subpage = 0;
  static uint32_t med_subpage = 0;

  /// Lower and upper limits for histogram
  static int min_temp;
  static int max_temp;

  if (tempdata->min_info.temp >= tempdata->max_info.temp) {
    return;
  }

  bool subpage = tempdata->subpage;

  if (subpage)
  {
    min_subpage = tempdata->min_info.temp;
    max_subpage = tempdata->max_info.temp;
    avg_subpage = tempdata->avg_temp;
    med_subpage = tempdata->med_temp;
  }
  else
  {
    min_sum = min_subpage + tempdata->min_info.temp;
    max_sum = max_subpage + tempdata->max_info.temp;
    avg_sum = avg_subpage + tempdata->avg_temp;
    med_sum = med_subpage + tempdata->med_temp;

    int margin = (max_sum - min_sum + 31) >> 3;

    min_temp = min_avg.exec(min_sum - (margin >> 2), margin) >> 1;
    max_temp = max_avg.exec(max_sum + (margin >> 2), margin) >> 1;

    if (min_temp >= max_temp) {
      std::swap(min_temp, max_temp);
      --min_temp;
      ++max_temp;
    }
  }
  
  int temp_diff = max_temp - min_temp;
  if (temp_diff == 0) return;
  int div = (1<<24) / temp_diff;

  // for (int y = 0; y < 24; ++y)
  // {
  //   bool shift = (subpage ^ y) & 1;
  //   auto src = &tempdata->data[y * 16];

  //   auto value = &values[y*32];
  //   for (int x = 0; x < 16; ++x)
  //   {
  //     value[(x<<1) + shift] = src[x];
  //   }
  // }
  for (int y = 0; y < 24; ++y)
  {
    bool shift = (subpage ^ y) & 1;
    auto src = &tempdata->data[y * 16];
    auto value = &values[y*32];
    for (int x = 0; x < 16; ++x)
    {
      value[31 - ((x<<1) + shift)] = src[x];
    }
  }

  // Display min and max temperature in Celsius at the top
  float minC = (min_temp / 128.0f) - 64.0f;
  float maxC = (max_temp / 128.0f) - 64.0f;

  for (int y = 0; y < 24; ++y)
  {
    auto vy0 = camera_area.y + (camera_area.h *  y    / 24);
    auto vy1 = camera_area.y + (camera_area.h * (y+1) / 24);
    bool shift = ((subpage ^ y) & 1);
    for (int x = 0; x < 16; ++x)
    {
      int xpos = (x<<1)+(shift);
      auto vx0 = camera_area.x + (camera_area.w *  xpos    >> 5);
      auto vx1 = camera_area.x + (camera_area.w * (xpos+1) >> 5);
      int pn = xpos + y*32;
      int temp = values[pn];
      bool lowtemp = (tempdata->min_info.temp >= temp);
      bool hightemp = (tempdata->max_info.temp <= temp);

      temp = (temp - min_temp) * div >> 16;
      if (temp < 0) temp = 0;
      else if (temp > 255) temp = 255;
      StickCP2.Display.fillRect(vx0, vy0, vx1 - vx0, vy1 - vy0, color_table[temp]);

      if (tempdata->diff_info.x == xpos && tempdata->diff_info.y == y)
      {
        StickCP2.Display.drawRect(vx0 + 1, vy0 + 1, vx1 - vx0 - 2, vy1 - vy0 - 2, 0xFF00FFu);
      }
      if (tempdata->min_info.x == xpos && tempdata->min_info.y == y)
      {
        StickCP2.Display.drawRect(vx0, vy0, vx1 - vx0, vy1 - vy0, 0x00FFFFu);
      }
      else
      if (tempdata->max_info.x == xpos && tempdata->max_info.y == y)
      {
        StickCP2.Display.drawRect(vx0, vy0, vx1 - vx0, vy1 - vy0, 0xFFFF00u);
      }
    }
  }

  StickCP2.Display.setTextSize(2);
  StickCP2.Display.setTextColor(TFT_SKYBLUE, TFT_BLACK);
  String minStr = String(minC, 1) + "C";
  StickCP2.Display.drawString(minStr, 5, 105);
  StickCP2.Display.setTextColor(TFT_RED, TFT_BLACK);
  String maxStr = String(maxC, 1) + "C";
  StickCP2.Display.drawRightString(maxStr, StickCP2.Display.width() - 2, 105);
  
  // print battery voltage
  int32_t level = StickCP2.Power.getBatteryLevel();
  StickCP2.Display.setTextColor(TFT_WHITE, TFT_BLACK);
  StickCP2.Display.setTextSize(1);
  StickCP2.Display.setCursor(5, StickCP2.Display.height() - StickCP2.Display.fontHeight() - 5);
  StickCP2.Display.printf("Battery: %d%%", level);
}

void drawCheck()
{
  StickCP2.Display.setTextSize(1);
  int fh = StickCP2.Display.fontHeight();
  StickCP2.Display.setTextColor(TFT_WHITE, TFT_BLACK);

  for (int i = 0; i < check_list_max; ++i)
  {
    if (check_prev[i] == check_list[i]) { continue; }
    uint_fast8_t val = check_list[i];
    check_prev[i] = val;
    int y = i;
    StickCP2.Display.setCursor( 5 , y * fh + 126);

    switch (val) {
    default:
      if (val == check_state_t::progress) {
        StickCP2.Display.setTextColor(0xFFFFFFu, 0x181818u);
      } else {
        StickCP2.Display.setTextColor(0xAAAAAAu, 0x181818u);
      }
      StickCP2.Display.print(test_name[i]);
      break;

    case check_state_t::failed:
      StickCP2.Display.setTextColor(0xFFFF00u, 0xFF0000u);
      StickCP2.Display.print("  FAILED  ");
      break;

    case check_state_t::success:
      StickCP2.Display.setTextColor(0x000000u, 0x00C000u);
      StickCP2.Display.print(" COMPLETE ");
      break;
    }
  }
}

void loop() {
  // StickCP2.update();  // Back to StickCP2

  // if (StickCP2.BtnA.wasPressed()) {  // Back to StickCP2
  //   Serial.println("Button A pressed!");
  // }
  
  // if (StickCP2.BtnB.wasPressed()) {  // Back to StickCP2
  //   Serial.println("Button B pressed!");
  // }

  drawCheck();
  drawThermalImage();
}
