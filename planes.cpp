#include<iostream>
#include<vector>

struct p_pos{
  float x, y;
};

std::vector<p_pos> generate_positions(float speed){

    std::vector<p_pos> pos;
    const int count = 10;

    for(int i = 0; i< count; i++){
        p_pos tmp;
        tmp.x = speed * i;
        tmp.y = speed * i;
        pos.push_back(tmp);
    }
    return pos;
}

int main(){

    std::string message = "This is a plane tracking program";

    std::cout<<message<< "\n";
    
    std::vector<int> plane_map;
    int nx=10, ny=10;

    float x_sz= 100.0, y_sz = 100.0;
    float dx = x_sz/nx, dy = y_sz/ny;


    plane_map.resize(nx * ny);

    /*p_pos tmp;
    tmp.x = 50;
    tmp.y = 30;
*/
    auto pos = generate_positions(50);
    for(int i = 0; i < pos.size(); i++){
      p_pos tmp = pos[i];
      int ix, iy;
      ix = tmp.x/dx;
      iy = tmp.y/dy;
      std::cout<<"Position "<<tmp.x<<" "<<tmp.y<<" is in cell "<<ix<<" "<<iy<<'\n';
      if(ix>0 && ix < nx and iy>0 and iy<ny){
        plane_map[ix + nx*iy]++;
      }
    }
    bool flag = true;
    if(flag){
    }


    int max=0, min=0;
    for(auto val: plane_map){
        if(val > max){
            max = val;
        }
        if(val < min) min = val;
    }
    std::cout<<"minimum number of planes "<<min<<"\n";
    std::cout<<"maximum number of planes "<<max<<"\n";

}