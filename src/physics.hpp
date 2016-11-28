class RigidbodySquare{
  public:
    float width, height, posx, posy;
  void init(float h, float w, float x, float y);
  void gravity();
};

class RigidbodyCircle{
  public:
    float radius, posx, posy;
  void init(float r, float x, float y);
};
