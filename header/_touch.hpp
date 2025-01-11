bool is_touch(SDL_Rect obj, SDL_Rect player)
{
    int center_obj = obj.x + (obj.x / 2);
    int left_obj = center_obj - (obj.w / 2);
    int right_obj = center_obj + (obj.w / 2);

    if (player.y == obj.y && (player.x > obj.x - 10 && player.x < obj.x + obj.w)) {
        return true;
    }

    return false;
}