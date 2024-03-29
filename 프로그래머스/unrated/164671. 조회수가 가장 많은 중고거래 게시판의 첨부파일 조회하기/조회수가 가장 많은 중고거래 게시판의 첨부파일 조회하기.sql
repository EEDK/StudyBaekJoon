SELECT CONCAT('/home/grep/src/', ug.BOARD_ID, '/',ug.FILE_ID, ug.FILE_NAME, ug.FILE_EXT) AS FILE_PATH
FROM USED_GOODS_BOARD bg
INNER JOIN USED_GOODS_FILE ug ON bg.BOARD_ID = ug.BOARD_ID
WHERE bg.VIEWS = (SELECT MAX(VIEWS) FROM USED_GOODS_BOARD)
ORDER BY ug.FILE_ID DESC;
