SELECT 
    contest_id,
    ROUND(COUNT(r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register AS r
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;