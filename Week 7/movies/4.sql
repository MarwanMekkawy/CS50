select count(title) from movies join ratings on movies.id = ratings.movie_id
where rating =10 ;
