-- 6. Average rating of movies in 2012
SELECT AVG(rating)
FROM ratings
JOIN movies on ratings.movie_id = movies.id
WHERE movies.year = 2012;
