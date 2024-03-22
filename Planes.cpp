#include <string>
#include <iostream>
#include <vector>

struct pos{

  float x=0.0, y=0.0;

};

std::vector<pos> generate_pos(float speed){
    const int count = 10;
    std::vector<pos> pos_list;
    for(int i =0; i < count; ++i ){
        pos tmp;
        tmp.x = speed * i;
        tmp.y = speed * i;
        pos_list.push_back(tmp);
    }
    return pos_list;

}


int main(){

  std::string message; 
  message = "This is a plane tracing program";

  // Print the message
  std::cout<<message<<'\n';
  
  const int n_i = 100, n_j = 100;
  float sz_x = 1000.0, sz_y = 1000.0;
  float dx = sz_x/n_i, dy=sz_y/n_j;

  std::vector<int> grid;

   grid.resize(n_i * n_j);

   int n_planes = 3;

   for(int n_p = 0; n_p < n_planes; ++n_p){

     std::vector<bool> tmp_map;
     tmp_map.resize(n_i* n_j);

     auto positions = generate_pos(7.5 * (n_p +1));

     for( auto my_position : positions){

       int ix = my_position.x / dx;
       int iy = my_position.y / dy;
       std::cout<<"Position "<< my_position.x<<" "<<my_position.y<<" is in cell "<< ix<< " "<< iy<<'\n';

       if(ix > 0 && iy > 0 && ix < n_i && iy < n_j && !tmp_map[ix + n_i*iy]){
        grid[ix + n_i * iy] ++;
        tmp_map[ix + n_i*iy] = true;
       }
     }
   }

  int min=0, max=0;
  for( auto item : grid ){
    if(item < min) min = item;
    if(item > max ) max = item;

  }

  std::cout<<"The minimum is "<<min<<'\n';
  std::cout<<"The maximum is "<<max<<'\n';


}