select title from movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
where people.name in ("Bradley Cooper","Jennifer Lawrence")
GROUP BY movies.title
HAVING COUNT(DISTINCT people.name) = 2;
