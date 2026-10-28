SELECT
    s.user_id,
    COALESCE(
        ROUND(
            SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END)
            / NULLIF(COUNT(c.action), 0),
            2
        ),
        0.00
    ) AS confirmation_rate
FROM Confirmations AS c
RIGHT JOIN Signups AS s
    ON c.user_id = s.user_id
GROUP BY s.user_id;