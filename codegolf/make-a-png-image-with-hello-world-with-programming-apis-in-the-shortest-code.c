/*

So, I want you to make a PNG image that says "Hello world!" and nothing else on a distinguishable background using only an image making API (eg ImageMagick) and return the image.
Fewest characters win, as usual. Oh, and you can use any color text.

*/

#include <cairo.h>

int
main(void)
{
	static const char text[] = "Hello, World!";

	cairo_surface_t *surface;
	cairo_t *cr;
	cairo_text_extents_t ex;
	int x, y, w, h;

	w = 256;
	h = 128;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
	cr = cairo_create(surface);
	cairo_select_font_face(cr, "Courier",
	                       CAIRO_FONT_SLANT_NORMAL,
	                       CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 32);

	cairo_text_extents(cr, text, &ex);
	x = (w / 2) - (ex.width / 2 + ex.x_bearing);
	y = (h / 2) - (ex.height / 2 + ex.y_bearing);

	cairo_set_source_rgb(cr, 0.1, 0.1, 0.1);
	cairo_paint(cr);

	cairo_set_source_rgb(cr, 0.5, 0.6, 0.7);
	cairo_move_to(cr, x, y);
	cairo_show_text(cr, text);
	cairo_stroke(cr);

	cairo_surface_write_to_png(surface, "hello_world.png");

	cairo_surface_destroy(surface);
	cairo_destroy(cr);

	return 0;
}
