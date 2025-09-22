select distinct people.name
from people
join stars on stars.person_id = people.id
where stars.movie_id in (
    select stars.movie_id
    from stars
    join people on people.id = stars.person_id
    where people.name = "Kevin Bacon"
)
and people.name <> "Kevin Bacon";
