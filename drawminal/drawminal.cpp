#include "drawminal.h"
#include <cmath>
#include <cstring>
#define PI 3.14159265

std::vector<std::string> braille_map = {
    "\u2800", "\u2801", "\u2802", "\u2803", "\u2804", "\u2805", "\u2806", "\u2807", "\u2808", "\u2809", "\u280A", "\u280B", "\u280C", "\u280D", "\u280E", "\u280F",
    "\u2810", "\u2811", "\u2812", "\u2813", "\u2814", "\u2815", "\u2816", "\u2817", "\u2818", "\u2819", "\u281A", "\u281B", "\u281C", "\u281D", "\u281E", "\u281F",
    "\u2820", "\u2821", "\u2822", "\u2823", "\u2824", "\u2825", "\u2826", "\u2827", "\u2828", "\u2829", "\u282A", "\u282B", "\u282C", "\u282D", "\u282E", "\u282F",
    "\u2830", "\u2831", "\u2832", "\u2833", "\u2834", "\u2835", "\u2836", "\u2837", "\u2838", "\u2839", "\u283A", "\u283B", "\u283C", "\u283D", "\u283E", "\u283F",
    "\u2840", "\u2841", "\u2842", "\u2843", "\u2844", "\u2845", "\u2846", "\u2847", "\u2848", "\u2849", "\u284A", "\u284B", "\u284C", "\u284D", "\u284E", "\u284F",
    "\u2850", "\u2851", "\u2852", "\u2853", "\u2854", "\u2855", "\u2856", "\u2857", "\u2858", "\u2859", "\u285A", "\u285B", "\u285C", "\u285D", "\u285E", "\u285F",
    "\u2860", "\u2861", "\u2862", "\u2863", "\u2864", "\u2865", "\u2866", "\u2867", "\u2868", "\u2869", "\u286A", "\u286B", "\u286C", "\u286D", "\u286E", "\u286F",
    "\u2870", "\u2871", "\u2872", "\u2873", "\u2874", "\u2875", "\u2876", "\u2877", "\u2878", "\u2879", "\u287A", "\u287B", "\u287C", "\u287D", "\u287E", "\u287F",
    "\u2880", "\u2881", "\u2882", "\u2883", "\u2884", "\u2885", "\u2886", "\u2887", "\u2888", "\u2889", "\u288A", "\u288B", "\u288C", "\u288D", "\u288E", "\u288F",
    "\u2890", "\u2891", "\u2892", "\u2893", "\u2894", "\u2895", "\u2896", "\u2897", "\u2898", "\u2899", "\u289A", "\u289B", "\u289C", "\u289D", "\u289E", "\u289F",
    "\u28A0", "\u28A1", "\u28A2", "\u28A3", "\u28A4", "\u28A5", "\u28A6", "\u28A7", "\u28A8", "\u28A9", "\u28AA", "\u28AB", "\u28AC", "\u28AD", "\u28AE", "\u28AF",
    "\u28B0", "\u28B1", "\u28B2", "\u28B3", "\u28B4", "\u28B5", "\u28B6", "\u28B7", "\u28B8", "\u28B9", "\u28BA", "\u28BB", "\u28BC", "\u28BD", "\u28BE", "\u28BF",
    "\u28C0", "\u28C1", "\u28C2", "\u28C3", "\u28C4", "\u28C5", "\u28C6", "\u28C7", "\u28C8", "\u28C9", "\u28CA", "\u28CB", "\u28CC", "\u28CD", "\u28CE", "\u28CF",
    "\u28D0", "\u28D1", "\u28D2", "\u28D3", "\u28D4", "\u28D5", "\u28D6", "\u28D7", "\u28D8", "\u28D9", "\u28DA", "\u28DB", "\u28DC", "\u28DD", "\u28DE", "\u28DF",
    "\u28E0", "\u28E1", "\u28E2", "\u28E3", "\u28E4", "\u28E5", "\u28E6", "\u28E7", "\u28E8", "\u28E9", "\u28EA", "\u28EB", "\u28EC", "\u28ED", "\u28EE", "\u28EF",
    "\u28F0", "\u28F1", "\u28F2", "\u28F3", "\u28F4", "\u28F5", "\u28F6", "\u28F7", "\u28F8", "\u28F9", "\u28FA", "\u28FB", "\u28FC", "\u28FD", "\u28FE", "\u28FF"
};

namespace drawminal {

Drawminal::Drawminal(short w_ratio, short h_ratio)
	: _w_ratio(w_ratio), _h_ratio(h_ratio), _linear_length(_w_ratio * _h_ratio)
{
    for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawminal::Drawminal(void *context, short w_ratio, short h_ratio)
	: _w_ratio(w_ratio), _h_ratio(h_ratio), _linear_length(_w_ratio * _h_ratio)
{
    for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawminal::~Drawminal() {}

void Drawminal::draw(const char *s, int x, int y)
{
    put(s, x, y);
}

void Drawminal::draw(const std::vector<Point2D>& points)
{
    for (auto i : points) set_buffer(i.get_x(), i.get_y());
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? u8"\u283F" : " ");
    std::cout << s << std::flush;
    set_cursor_pos(1, 1);
}

/*
void Drawminal::draw(const std::vector<Point2D>& points)
{
    for (auto i : points) set_buffer(i.get_x(), i.get_y());
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    std::cout << s;
    set_cursor_pos(1, 1);
}

void Drawminal::draw(const std::vector<Point2D>& points)
{
    for (auto i : points) set_buffer(i.get_x(), i.get_y());
    std::string shape("");
    // for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    auto sb = get_screen_buffer(points);
    for (int i = 0; i < sb.size(); ++i) {
        set_cursor_pos(points[i].get_x(), points[i].get_y());
        std::cout << (sb[i] ? u8"\u2550" : " ");
        // std::cout << sb[points] << std::flush;
    }
    set_cursor_pos(1, 1);

}
*/

void Drawminal::draw(const Shape2D& shape)
{
    auto points = shape.get_bounds();
    for (auto i : points) {
        int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
        // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
        _buffer[yr * get_width() + xr] |= pixel_map[y % _h_ratio][x % _w_ratio];
    }
}

void Drawminal::erase(const std::vector<Point2D>& points)
{
    for (auto i : points) unset_buffer(i.get_x(), i.get_y());
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? "." : " ");
    std::cout << s << std::flush;
    set_cursor_pos(1, 1);
}

void Drawminal::erase(const Shape2D& shape)
{
    auto points = shape.get_bounds();
    for (auto i : points) {
        int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
        _buffer[yr * get_width() + xr] &= ~pixel_map[y % _h_ratio][x % _w_ratio];
    }
}

void Drawminal::print(void)
{
    std::string s;
    for (auto i : _buffer)
        s += (i ? braille_map[i] : " ");
    std::cout << s;
    set_cursor_pos(1, 1);
}

} // namespace drawminal
