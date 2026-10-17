SELECT ROUND(
    COUNT(*) / (SELECT COUNT(DISTINCT player_id) FROM Activity),
    2
) AS fraction
FROM Activity AS a
INNER JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) AS f
    ON a.player_id = f.player_id
WHERE DATEDIFF(a.event_date, f.first_login) = 1;