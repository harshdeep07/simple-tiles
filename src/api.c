#include <stdlib.h>
#include "simple_tiles.h"

int
main(){
  simplet_map_t *map;

  if(!(map = simplet_map_new(map)))
    exit(1);

  simplet_map_set_srs(map, "+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs");
  simplet_map_set_size(map, 600, 300);
  simplet_map_set_bounds(map, -179.231086, 17.831509, -60.859681, 71.441059);
  // Only one layer per map for now
  simplet_map_add_layer(map, "../data/tl_2010_us_cd108.shp");
  //simplet_map_add_rule(map,  "SELECT * from tl_2010_us_county10 where STATEFP10 = '05'");
  //simplet_map_add_style(map, "fill",   "#cc0000");
  //simplet_map_add_style(map, "stroke", "#aaaaaa");
  //simplet_map_add_rule(map,  "SELECT * from tl_2010_us_county10 where STATEFP10 = '10'");

  simplet_map_add_rule(map,  "SELECT * from tl_2010_us_cd108");
  simplet_map_add_style(map, "fill",   "#aa0000");
  simplet_map_add_style(map, "weight", "0.1");
  simplet_map_add_style(map, "stroke", "#444444");
  
  if(simplet_map_isvalid(map))
    simplet_map_render_to_png(map, "./out.png");

  simplet_map_free(map);
}